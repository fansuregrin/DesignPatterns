# Singleton
单例模式。

## 意图
单例模式是一种创建型设计模式， 让你能够保证一个类只有一个实例， 并提供一个访问该实例的全局节点。

## 模式结构
![](./Singleton.png)

## 实现
### 内部静态变量懒汉式👍
自 C++ 11 起线程安全，推荐使用这种方式。
```c++
class Singleton {
public:
    static Singleton &getInstance() {
        static Singleton instance;
        return instance;
    }
private:
    Singleton() noexcept {}
    ~Singleton() {}
};
```

### 饿汉式
饿汉式是线程安全的。

```c++
class Singleton {
public:
    static Singleton &getInstance() {
        return *p_instance;
    }
private:
    Singleton() noexcept {}
    ~Singleton() {}
    static Singleton * p_instance;
};

// 在静态存储区（data section）构建全局对象
Singleton * Singleton::p_instance = new Singleton();
```

### 懒汉式（不加锁）
非线程安全。
```c++
class Singleton {
public:
    static Singleton &getInstance() {
        if (p_instance == nullptr) {
            p_instance = new Singleton();
        }
        return *p_instance;
    }
private:
    Singleton() noexcept {}
    ~Singleton() {}
    static Singleton * p_instance;
};

Singleton * Singleton::p_instance = nullptr;
```

### 饿汉式（加锁）
线程安全，但是性能开销大。
```c++
class Singleton {
public:
    static Singleton &getInstance() {
        lock_guard<mutex> lck(mtx);
        if (p_instance == nullptr) {
            p_instance = new Singleton();
        }
        return *p_instance;
    }
private:
    mutable mutex mtx;
    Singleton() noexcept {}
    ~Singleton() {}
    static Singleton * p_instance;
};

Singleton * Singleton::p_instance = nullptr;
```
# day day cxx

It's a Study Project to learn C++ day by day.

## -01 KString
实现string以下api，内部不能使用string，只能用数组存字符<br> 
```
auto str1 = CustomString("test1");  
auto str2 = CustomString("test2, test3");  
str1 = "test3";  
int len = str1.len();  
CustomString sub1 = str1.sub(1,2);  
str1.append("append");  
bool equal = str1 == str2;  
int index = str1.find("es"); 
CustomString* ret = str2.split(",");  
```

## -02 KArray & KList
实现数组以及一下api<br>
```
auto arr = new CustomArray();
arr.reserve(4);
arr.push(1);
arr.push(2);
arr.insert(1, 3);
arr.remove(1);
arr.pop();
arr.clear();
int index = arr.findIndex(1);
```
<br>

实现双向链表以下api
```
auto list1 = new CustomList();
auto node1 = list1.push(1);
auto node2 = list1.push(2);
auto node3 = list1.insert(node2, 3);
auto ret = list1.find(2);
list1.remove(node2);
list1.popAll();
```
<br>

做完上面的再改成带模板的
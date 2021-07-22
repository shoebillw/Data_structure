# Execution result

![image](https://user-images.githubusercontent.com/80030514/126644209-dfa630e0-2729-4b7a-afa6-02da93a4b778.png)

(1,36) -> 將job 36 分配給 machine 1

# Explain

(1) 將使用者輸入的各個job time 存進input[]中，並且按照工作時間長到短進行排序

(2) time[]是用來儲存各機器現在執行工作時間總長度，time[0]是第一台機器 time[1]是第2台機器 以此類推

(3) 先把最長時間的工作拿出來，看看哪一台機器目前總工作時間最短，就交給那台機器來做。並且輸出該工作交給哪台機器做&工作時長

(4)再來看第二長時間的工作，當下哪台機器的工作總時間最短，以此類推

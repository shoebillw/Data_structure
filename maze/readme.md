# 輸出結果

![image](https://user-images.githubusercontent.com/80030514/126645109-88d803ba-b13d-487b-829b-40dbd8c0017c.png)


# 程式執行流程

1.先利用array與一些function實作出stack的性質(因為stack中必須要儲存迷宮的X軸與Y軸所以設了2個stack)

2.將(0,0)放入stack 中

3.進迴圈

4.每次移動前把當下的位置標記成-1

5.先判斷走到終點了沒，到了就跳出迴圈

6.判斷右邊是不是0 是就走過去(把目標點放入stack中)

6.2不是就判斷下面 再不是就左邊 再不是就上面

7.再不是的話 就把當下那點標記成2，再倒退一格

8.直到走到終點為止

標記成-1的點就是路徑

標記成2的點是走過但死路的地方

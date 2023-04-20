# Arduino Tracking Car

## 一、使用材料

|品項 |品名 |數量 |備註 |
|:-: |:-: |:-: |:-: |
|1 |Arduino |2 ||
|2 |紅外線感測器|3 ||
|3 |馬達 |2 ||
|4 |電池 |1 |組 |
|5 |輪子 |2 ||
|6 |輔助輪 |1 ||
|7 |車板 |1 ||
|8 |馬達控制器 L298N |1 ||
|9 |杜邦線 |1 |捆 |

## 二、作業目的
### 1、利用與紅外線感測器，讓智能小車自己循著黑色膠帶前進
![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/IR.jpeg?raw=true) ![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Tracking.png?raw=true)
### 三、實際成品

![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Arduino%20Car.jpeg?raw=true)

#### 真值表 （如下）： 0 為紅外線偵測到黑色膠帶
|狀態 |執行動作 |備註 |
| :-: | :-: | :-: |
|000 |前進 |三個 IR 皆在黑色膠帶上，可能因三個 IR 前後位置不一導致出現 IR 皆感測到膠帶<br>故設定前進重新偵測。 |
|001 |左轉 |車子微偏右 |
|010 |後退 |因不可能發生，但三個 IR 前後位置不一以免萬一<br>這是第二行。故設定退後重新偵測。 |
|011 |左轉 |車子偏右 |
|100 |右轉 |車子微偏左 |
|101 |前進 |正常狀況 |
|110 |右轉 |車子偏左 |
|111 |後退 |已偏離軌道，故設定退後重新偵測。 |
### 四、程式碼
|![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Code1.jpeg?raw=true)|
![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Code2.jpeg?raw=true)
![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Code3.jpeg?raw=true)
![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Code4.jpeg?raw=true)
![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Code5.jpeg?raw=true)
![](https://github.com/Yen-Wei-Liang/Arduino-Tracking-Car-/blob/main/image/Code6.jpeg?raw=true)

import cv2 as cv

#读入图片
img = cv.imread("E:\\code\\python\\Opencv\\apple.png")
#对图像模糊处理
img=cv.blur(img,(3,3))
#将BGR空间转化为HSV空间
hsvImg =cv.cvtColor(img, cv.COLOR_BGR2HSV)
#单独取出H通道
colorImage=hsvImg[:,:,0:1]

#阀值
#经检测苹果上部H值Hup->0，下部H值Hdown->180,其余部分H值Hothers小于Hup，大于Hdown
ret,colorImage=cv.threshold(colorImage,140,160,cv.THRESH_TOZERO_INV)#让苹果上部Hip<Hdown，使得苹果与其余部分的灰度值有一个二分的边界
ret,colorImage=cv.threshold(colorImage,11,180,cv.THRESH_BINARY)#让整个图片灰度0-1化

#检测轮廓，RETR_LIST参数将许多轮廓构成一个线性表
contours, hierarchy = cv.findContours(colorImage, cv.RETR_LIST,cv.CHAIN_APPROX_NONE)

# 在图上画出轮廓，颜色为红色
draw_img = img.copy()
res = cv.drawContours(draw_img, contours, 44, (0, 0, 255), 2)
cv.imshow("res",res)

'''
找到最优轮廓的测试模块
for i in range(len(contours)):
    res=cv.drawContours(draw_img, contours, i, (0, 0, 255), 2)
    cv.imshow(str(i), res)
'''
#外接圆
draw_img2 = img.copy()
(x, y), r = cv.minEnclosingCircle(contours[44])
center = (int(x)-5, int(y)+60)
radius = int(r)-30#
circle = cv.circle(draw_img2, center, radius, (0, 255, 0), 2)
cv.imshow('circle', circle)


cv.waitKey(0)
import matplotlib.pyplot as plt
from wordcloud import WordCloud,ImageColorGenerator
import jieba
import imageio
mk = imageio.imread("logo.png")

# 将外部文件包含的文本保存在text变量中
text = open('words.txt').read()
txtlist = jieba.lcut(text)
string = " ".join(txtlist)

# 构建词云对象w
wc = WordCloud(background_color="white",
               mask=mk,
               font_path='STHeiti Light.ttc',
               max_words = 400,
               scale = 5,
               max_font_size=120,
               stopwords={"自己","我们","可以","但是","使用","一个","同时","一些","之前","一点","正在","很大","甚至","如果","不断"})
# 将text字符串变量传入w的generate()方法，给词云输入文字
wc.generate(string)

# 调用wordcloud库中的ImageColorGenerator()函数，提取模板图片各部分的颜色
image_colors = ImageColorGenerator(mk)

# 给词云对象按模板图片的颜色重新上色
wc_color = wc.recolor(color_func=image_colors)
# 将词云图片导出到当前文件夹
wc_color.to_file('wco2.png')
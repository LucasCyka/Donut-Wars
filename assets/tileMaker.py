from PIL import Image
import os

i = []

tileSet = Image.new("RGBA",(1280,128)) 

id = 0

for file in sorted(os.listdir(os.getcwd())):
	
	if file.endswith(".png"):
		with Image.open(file) as img:
			print(file)
			i.append(img)
			tileSet.paste(img,box=(id*img.width,0))	

		id = id +1

#tileSet.show()
tileSet.save("newTileset.png")


for img in i:
	img.close()

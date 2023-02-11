from PIL import Image

class Resize_Images():
    def __init__(self):
        return

    def resize(self,size,image_path,output_path):
        original_image = Image.open(image_path)
        width, height = original_image.size
        print("The original image size is: (%d, %d)" % (width, height))

        resized_image = original_image.resize(size)
        width, height = resized_image.size
        print("The resized image size is: (%d, %d)" % (width, height))
        resized_image.show()
        resized_image.save(output_path)



image_path = "IMG_0011.png"
output_path = "ipad_2nd.png"
size = (2048,2732)
obj = Resize_Images()
obj.resize(size,image_path, output_path)



# 자료형

# 1. Integer
a = 123
a = -178
a = 0

# 2. Floating-point
a = 1.2
a = -3.45
a = 4.24E10 # 4.24 * 10^10
a = 4.24e-10 # 4.24 * 10^-10

# 3. Octal Number
a = 0o177

# 4. Hexadecimal Number
a = 0x8ff
a = 0xABC

# 사칙연산
a = 3
b = 4
print(a + b)
print(a - b)
print(a*b)
print(a/b)
print(a//b)
print(a%b)
print(a**b)

# String 문자열
a = "Hello World"
a = 'Python is fun'
# ""와 '' 모두 가능
a = """Life is too short,
You need python
"""
a = '''Life is too short,
You need python
'''
print(a)

# 따옴표안에 따옴표 넣기
a = "Python`s favorite food is perl"
print(a)
a = 'python is very easy" he say.'
print(a)
a = 'python \'s favorite food is perl'
print(a)
a = "\"Python is very easy.\" he says."
print(a)
# 줄 바꿈
a = "Life is too short\nYou need python"
print(a)
# \n 줄 바꿈
# \t 탭 간격 
# \\ 슬래시 문자 그대로 사용
# \r 캐리지 리턴(커서를 제일 앞으로)
# \b 백스페이스
# \000 Null 문자

# 문자열 연산
head = "Python"
tail = " is Fun!"
print(head+tail)
print(head*3)
print("="*50)
print("My Program")
print("="*50)
a = "Life is too short"
print(len(a))
a = "Life is too short, You need Python"
print(a[0])
print(a[1])
print(a[2])
print(a[3])
print(a[4])
print(a[5])
print(a[-1])
b = a[0] + a[1] + a[2] + a[3]
print(b)
print(a[0:4])
print(a[0:3]) # 이상 ~ 미만이기 때문에 짤려서 출력
print(a[0:5])
print(a[5:7])
print(a[12:17])
a = "Pithon"
print(a[:1])
print(a[2:])
print(a[:1] + 'y' + a[2:])
# Formating 
number = 3
print(f"I eat {number} apples")
name = "홍길동"
age = 30
print(f"나의 이름은 {name}입니다. 나이는 {age}입니다.")
print(f"나는 내년에 {age+1}살이 된다. 무야호 {30+40}")
d = {'name': '홍길동', 'age':30}
print(f"나의 이름은 {d['name']}이고, 나이는 {d['age']}살")

# 문자열 관련 메서드
a = "hobby"
print(a.count('b'))
a = "Python is the best choice"
print(a.find('b'))
print(a.find('k'))
a = "Life is too short"
print(a.index('t'))
# print(a.index('k'))
print(",".join(a))
print(",".join(['a','b','c','d']))
a = "lower"
print(a.upper())
a = "UPPER"
print(a.lower())
a = "  Hi  "
print(a.lstrip()) 
print(a.rstrip())
print(a.strip())
a ="Life is too short"
print(a.replace("Life", "Your leg"))
print(a.split())
b = "a:b:c:d"
print(b.split(':'))



Output exceeds the size limit. Open the full output data in a text editor
['AlexNet',
 'AlexNet_Weights',
 'ConvNeXt',
 'ConvNeXt_Base_Weights',
 'ConvNeXt_Large_Weights',
 'ConvNeXt_Small_Weights',
 'ConvNeXt_Tiny_Weights',
 'DenseNet',
 'DenseNet121_Weights',
 'DenseNet161_Weights',
 'DenseNet169_Weights',
 'DenseNet201_Weights',
 'EfficientNet',
 'EfficientNet_B0_Weights',
 'EfficientNet_B1_Weights',
 'EfficientNet_B2_Weights',
 'EfficientNet_B3_Weights',
 'EfficientNet_B4_Weights',
 'EfficientNet_B5_Weights',
 'EfficientNet_B6_Weights',
 'EfficientNet_B7_Weights',
 'EfficientNet_V2_L_Weights',
 'EfficientNet_V2_M_Weights',
 'EfficientNet_V2_S_Weights',
 'GoogLeNet',
...
 'vit_h_14',
 'vit_l_16',
 'vit_l_32',
 'wide_resnet101_2',
 'wide_resnet50_2']
Output exceeds the size limit. Open the full output data in a text editor
ResNet(
  (conv1): Conv2d(3, 64, kernel_size=(7, 7), stride=(2, 2), padding=(3, 3), bias=False)
  (bn1): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
  (relu): ReLU(inplace=True)
  (maxpool): MaxPool2d(kernel_size=3, stride=2, padding=1, dilation=1, ceil_mode=False)
  (layer1): Sequential(
    (0): Bottleneck(
      (conv1): Conv2d(64, 64, kernel_size=(1, 1), stride=(1, 1), bias=False)
      (bn1): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv2): Conv2d(64, 64, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1), bias=False)
      (bn2): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv3): Conv2d(64, 256, kernel_size=(1, 1), stride=(1, 1), bias=False)
      (bn3): BatchNorm2d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (relu): ReLU(inplace=True)
      (downsample): Sequential(
        (0): Conv2d(64, 256, kernel_size=(1, 1), stride=(1, 1), bias=False)
        (1): BatchNorm2d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      )
    )
    (1): Bottleneck(
      (conv1): Conv2d(256, 64, kernel_size=(1, 1), stride=(1, 1), bias=False)
      (bn1): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv2): Conv2d(64, 64, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1), bias=False)
      (bn2): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv3): Conv2d(64, 256, kernel_size=(1, 1), stride=(1, 1), bias=False)
...
    )
  )
  (avgpool): AdaptiveAvgPool2d(output_size=(1, 1))
  (fc): Linear(in_features=2048, out_features=1000, bias=True)
)
Output exceeds the size limit. Open the full output data in a text editor
ResNet(
  (conv1): Conv2d(3, 64, kernel_size=(7, 7), stride=(2, 2), padding=(3, 3), bias=False)
  (bn1): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
  (relu): ReLU(inplace=True)
  (maxpool): MaxPool2d(kernel_size=3, stride=2, padding=1, dilation=1, ceil_mode=False)
  (layer1): Sequential(
    (0): Bottleneck(
      (conv1): Conv2d(64, 64, kernel_size=(1, 1), stride=(1, 1), bias=False)
      (bn1): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv2): Conv2d(64, 64, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1), bias=False)
      (bn2): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv3): Conv2d(64, 256, kernel_size=(1, 1), stride=(1, 1), bias=False)
      (bn3): BatchNorm2d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (relu): ReLU(inplace=True)
      (downsample): Sequential(
        (0): Conv2d(64, 256, kernel_size=(1, 1), stride=(1, 1), bias=False)
        (1): BatchNorm2d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      )
    )
    (1): Bottleneck(
      (conv1): Conv2d(256, 64, kernel_size=(1, 1), stride=(1, 1), bias=False)
      (bn1): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv2): Conv2d(64, 64, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1), bias=False)
      (bn2): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
      (conv3): Conv2d(64, 256, kernel_size=(1, 1), stride=(1, 1), bias=False)
...
    )
  )
  (avgpool): AdaptiveAvgPool2d(output_size=(1, 1))
  (fc): Linear(in_features=2048, out_features=1000, bias=True)
)
c:\Users\Ahn_YeongHoo\AppData\Local\Programs\Python\Python310\lib\site-packages\torchvision\models\_utils.py:208: UserWarning: The parameter 'pretrained' is deprecated since 0.13 and will be removed in 0.15, please use 'weights' instead.
  warnings.warn(
c:\Users\Ahn_YeongHoo\AppData\Local\Programs\Python\Python310\lib\site-packages\torchvision\models\_utils.py:223: UserWarning: Arguments other than a weight enum or `None` for 'weights' are deprecated since 0.13 and will be removed in 0.15. The current behavior is equivalent to passing `weights=ResNet101_Weights.IMAGENET1K_V1`. You can also use `weights=ResNet101_Weights.DEFAULT` to get the most up-to-date weights.
  warnings.warn(msg)
Output exceeds the size limit. Open the full output data in a text editor
tensor([[-3.5062e+00, -1.6548e+00, -2.4362e+00, -3.2269e+00, -3.2554e+00,
         -1.3279e+00, -2.0387e+00, -2.5524e+00, -1.3135e+00, -2.8868e+00,
         -1.6769e+00, -1.2939e+00, -2.6270e+00, -2.9825e+00, -2.4422e+00,
         -2.8328e+00, -3.3203e+00, -7.9936e-01, -6.7416e-01, -1.2196e+00,
         -3.0347e+00, -3.9686e+00, -2.2680e+00, -1.0846e+00, -9.8041e-01,
         -1.0803e+00, -3.0981e+00, -2.4780e+00, -2.2128e+00, -3.1997e+00,
         -3.3046e+00, -1.8557e+00, -2.0713e+00, -2.1237e+00, -1.8610e+00,
         -3.2377e+00, -1.1214e+00, -1.1287e+00, -1.1627e+00, -9.0547e-01,
         -4.5834e-01, -1.5009e+00,  1.4361e+00,  1.3317e-01, -1.8419e+00,
         -1.4860e+00,  9.6656e-01, -9.4483e-01, -3.0352e+00, -2.7335e+00,
         -2.5975e+00, -2.0671e+00, -1.8187e+00, -1.9505e+00, -1.7909e+00,
         -1.3144e+00, -4.5241e-01, -2.0593e+00, -3.2940e+00, -4.8054e-01,
         -3.6595e-01, -1.1695e+00, -7.4092e-01, -1.4503e+00, -1.5090e+00,
         -2.1159e+00, -1.7185e+00, -4.1881e-01, -1.9233e+00, -1.5118e+00,
         -1.2118e+00, -1.3149e+00, -1.0743e+00,  1.2556e-01, -4.0026e-01,
         -2.5087e-01, -8.7345e-01,  5.8782e-01, -8.8669e-01,  1.4514e+00,
         -2.6447e+00, -3.6629e+00, -2.3796e-01, -5.1583e-02, -2.2709e+00,
         -2.3636e+00, -1.4068e+00,  2.4798e-01, -1.0566e+00, -2.9138e+00,
         -2.5347e+00, -2.2312e+00,  4.3151e-01, -1.3407e+00, -2.5460e-02,
         -2.8833e+00, -5.6503e-01, -1.3975e+00, -2.9335e+00, -1.9069e+00,
         -4.2475e+00, -2.9687e+00, -2.0563e+00, -2.4383e+00, -2.7777e+00,
         -4.0227e+00, -3.6547e+00, -4.8142e-01, -9.8892e-01, -1.8991e+00,
         -3.5530e+00, -1.4582e+00,  1.1147e+00, -6.9323e-01, -7.5059e-01,
         -2.1824e+00, -2.2511e+00, -5.3990e-01, -1.5104e+00, -2.6076e+00,
         -3.9957e+00, -9.7004e-01, -5.5196e-01, -8.6874e-01, -1.2145e+00,
...
         -4.4917e+00,  5.7550e-01, -1.3423e+00, -3.8161e+00, -7.9870e-01,
         -5.7727e-01, -2.5559e+00,  2.4096e+00,  6.6708e-01,  4.8536e-01,
          2.8808e+00, -3.7524e+00,  1.5161e+00, -3.2759e+00, -2.5039e+00,
         -3.2412e-01,  1.2739e-01, -1.1780e+00,  3.4409e+00,  4.4506e+00]],
       grad_fn=<AddmmBackward0>)
tensor([207])
('golden retriever', 96.57714080810547)
[('golden retriever', 96.57714080810547),
 ('Labrador retriever', 2.6046721935272217),
 ('cocker spaniel, English cocker spaniel, cocker', 0.2692059278488159),
 ('redbone', 0.17992474138736725),
 ('tennis ball', 0.10995148867368698)]

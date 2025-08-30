# LinuxDeviceDriverProgrammingWithRaspberryPi
라즈베리 파이 5 64bit를 이용한 리눅스 커널6 디바이스 드라이버 프로그래밍

리눅스 디바이스 드라이버 프로그래밍을 하기 위해서는 관련 헤더 파일 등의 리소스가 필요하다.
그리고 현재 사용하는 시스템의 커널과 관련된 헤더 파일의 버전이 맞아야하기 때문에 새로 커널을 컴파일해서 사용하면 좋은데
라즈베리 파이에서 리눅스 커널의 빌드는 라즈베리 파이 사이트를 참고하는 것이 좋다.
- https://www.raspberrypi.com/documentation/computers/linux_kernel.html

라즈베리 파이 5 64비트를 기준으로 리눅스 커널을 컴파일하려면 
라즈베리 파이에서 리눅스 커널을 컴파일하거나 PC에서 크로스플랫폼 환경에서 빌드하셔도 됩니다.
라즈베리 파이 4부터 속도가 상당히 빠라져서 라즈베리 파이에서 직접 빌드해도 큰 문제는 없을 것 같습니다.

설치는 아래와 같이 진행하면 됩니다. 먼저 필요한 패키지를 설치합니다.
- $ sudo apt install bc bison flex libssl-dev make git

그리고 리눅스 커널의 소스 코드를 다운로드 힙니다.
- $ git clone --depth=1 https://github.com/raspberrypi/linux
  
그리고 소스 코드를 위한 Makefile을 생성 합니다.
라즈베리 파이 5는 BCM2712를 사용하므로 kernel_2712 옵션을 사용합니다.
- $ cd linux-
- $ KERNEL=kernel_2712

소스 코드를 빌드합니다.
- $ make bcm2712_defconfig
- $ make -j6 Image.gz modules dtbs

모듈을 설치합니다.
- $ sudo make -j6 modules_install

시스템에 리눅스 커널을 설치합니다.
- $ sudo cp /boot/firmware/$KERNEL.img /boot/firmware/$KERNEL-backup.img
- $ sudo cp arch/arm64/boot/Image.gz /boot/firmware/$KERNEL.img
- $ sudo cp arch/arm64/boot/dts/broadcom/*.dtb /boot/firmware/
- $ sudo cp arch/arm64/boot/dts/overlays/*.dtb* /boot/firmware/overlays/
- $ sudo cp arch/arm64/boot/dts/overlays/README /boot/firmware/overlays/

설치가 다 끝나면 리부팅하고 리부팅 후 커널 버전을 확인합니다.
- $ sudo reboot
- $ uname -a
-  Linux raspberrypi 6.12.44-v8-16k+ #2 SMP PREEMPT Sat Aug 30 14:21:47 KST 2025 aarch64 GNU/Linux


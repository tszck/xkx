# xkx100
俠客行100 UTF-8 中文版

Updated the files to work with FluffOS following the guidelines in the following,
https://forum.fluffos.info/t/common-lpc-migration-issues-v2019/1341

## 使用説明

項目下載

    # clone xkx100
    git clone --recurse-submodules https://github.com/MudRen/xkx100.git
    # 更新mudcore框架(可選)
    git submodule update --remote

請使用 fluffos v2019 最新版驅動

    driver config.ini

遊戲端口：5555(GBK編碼)、6666(UTF8編碼)；網頁訪問端口：8888

本LIB為GBK舊版升級到utf-8版，目前代碼基本無編譯錯誤，原代碼BUG已基本修復，升級造成的BUG已知部分已修復，不過中文字符判斷（中文判斷`[0..1]`需要改為`[0..0]`）可能存在遺漏，目前已知存在以下問題：

1. 中文字符排版顯示未完全修復，比如地圖，會影響排版美觀；
2. 表情系統無效，因為emoted.o文件中空，可自己使用 edemote 指令補充；
3. 技能中文翻譯不全，因為e2c_dict.o是從[炎黃LIB](https://github.com/oiuv/mud)中複製過來的，對遊戲中顯示為英文的地方需要自己補充翻譯（補充方式如：chinese city=揚州）

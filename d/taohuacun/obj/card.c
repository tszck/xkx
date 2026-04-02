// card.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"賀卡"NOR, ({"card"}));
        set("unit", "張");
        set("long",HIR"

┏------------------ 新婚誌喜 ------------------┓
┃  ┌--------------------------------------┐  ┃
┃  │                                      │  ┃
┃  │                                      │  ┃
┃  │  invite  : 設定訪客名單。            │  ┃
┃  │  homename: 設定房間名稱。            │  ┃
┃  │  homedesc: 設定房間描述。            │  ┃
┃  │  bedname : 設定牀鋪名稱。            │  ┃
┃  │  beddesc : 設定牀鋪描述。            │  ┃
┃  │  findbaby: 找你們的小孩。            │  ┃
┃  │  gosleep : 上牀睡覺。這樣纔會有baby。│  ┃
┃  │  sleep <sb>: 創造愛的結晶。          │  ┃
┃  │                                      │  ┃
┃  │                    俠客行一百恭賀    │  ┃
┃  │                                      │  ┃
┃  └--------------------------------------┘  ┃
┗----------------------------------------------┛

"NOR);
        set("value", 0);
        set_weight(10);
        setup();
}

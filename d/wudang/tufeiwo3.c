// tufeiwo3.c 小路盡頭
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "小路盡頭");
	set("long", @LONG
你走在一條僻靜的林中小路上，兩旁是陰森森的樹林。只見左右前
後，到處都是鋪天蓋地的松樹林。幾十丈高的大松樹簇在一塊，密實的
枝葉象一蓬蓬巨傘般伸向天空，把陽光遮得絲毫也無。據說這裏經常有
土匪出沒，不可久留。
LONG );
	set("outdoors", "wudang");
	set("no_sleep_room",1);
	set("exits", ([
		"west" : __DIR__"tufeiwo2",
	]));
        set("objects", ([
                __DIR__"npc/tufei1" : 2 ,
                __DIR__"npc/tufeitou" : 1, 
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -1990);
	set("coor/y", -820);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

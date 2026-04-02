//JMQSHULIN4.C

inherit ROOM;

void create()
{
	set("short", "巨木旗樹林");
	set("long", @LONG
你眼前驟然一暗，朦朧中，只見左右前後，到處都是鋪天蓋地的不
知名的巨樹，好象松柏，又似冷杉，簇在一起，密實的枝葉象一蓬蓬巨
傘般伸向天空，遮天蔽日。你似乎迷失了方向，象沒頭蒼蠅般到處亂闖。
LONG );
	set("exits", ([
		"east" :  __DIR__"jmqshulin4",
		"west" :  __DIR__"jmqshulin4",
		"north" : __DIR__"jmqshulin5",
		"south" : __DIR__"jmqshulin4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
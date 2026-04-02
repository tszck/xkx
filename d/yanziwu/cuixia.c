//room: /d/yanziwu/cuixia.c
inherit ROOM;

void create()
{
	set("short","翠霞堂");
	set("long",@LONG
古樸莊嚴，氣度非凡，你一進門就不由的驚歎。好大一座廳堂！西
邊彷彿有一間小廳，東邊則是一片竹林，南面有一道穿堂，不知通向什
麼地方。
LONG );
	set("exits",([
		"west" : __DIR__"xiaoting",
		"east" : __DIR__"zhulin1",
		"south": __DIR__"chuantang",
	]));
	set("objects",([
		CLASS_D("murong")+"/azhu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1500);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
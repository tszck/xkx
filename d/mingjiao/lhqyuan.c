//lhqyuan.c
inherit ROOM;

void create()
{
	set("short", "烈火旗大院");
	set("long", @LONG
你走進了烈火旗的大院，卻發現這裏人聲鼎沸，烈火教衆有的在搬
火藥，有的在煉石油，真是熱火朝天。院子左首可能是練武場，隱約傳
來打鬥聲；右首是一座大廳，象是烈火旗的議會場所。向上走就是光明
頂明教總舵了。
LONG );
	set("exits", ([
		"west"    : __DIR__"lhqlwch",
		"northup" : __DIR__"lhqhoumen",
		"east"    : __DIR__"lhqdating",
		"out"     : __DIR__"lhqmen",
		"enter"   : __DIR__"huroom",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 1000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
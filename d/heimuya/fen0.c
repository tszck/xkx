// Room: /d/heimuya/fen0.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "風雷堂");
	set("long", @LONG
這裏是日月神教教下第一大堂。這裏距黑目崖不遠，教下第一大堂
堂主童百熊把掌此堂。
LONG);
	set("exits", ([
		"north" :  __DIR__"grass1",
	]));
	set("objects",([
            CLASS_D("heimuya")+"/tong" :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

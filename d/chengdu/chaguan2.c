// Room: /d/chengdu/chaguan2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "茶館二樓");
	set("long", @LONG
到這裏飲茶的人都是高雅之士，説話都不大聲，相互交談着各方面
的心得。推開窗戶，眺目遠望，芙蓉城美麗宜人的風光盡收眼底，徐徐
微風，吹着你的臉，再飲一口上等的“龍湖翠”悠哉，妙哉！
LONG );
	set("exits", ([
		"down" : __DIR__"chaguan",
	]));
	set("objects", ([
		__DIR__"obj/chair" : 3,
	]));
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



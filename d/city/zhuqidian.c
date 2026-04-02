// Room: /yangzhou/zhuqidian.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","竹器店");
	set("long",@LONG
「竹不產於揚州，揚州製品最精」，這家竹器店出售揚州精工巧匠
精心雕刻編制的竹器、木器。左牆倚牆碼着竹籃、竹簍、竹罩等平民百
姓的日常用品，中間的櫃檯擺着筆架、筆筒及小的竹木飾物。右牆掛着
幾幅空白扇面。看到你的到來，一個年輕夥計笑嘻嘻的迎了上來。
LONG );
	set("exits", ([
		"north" : __DIR__"matou",
	]));
	set("objects", ([
		__DIR__"npc/liusanshun" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
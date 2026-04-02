//ROOM qiushi.c

inherit ROOM;
void create()
{
	set("short", "囚室");
	set("long",@LONG
這是『靈鷲宮』關押犯人的地方，屋中光線昏暗，氣味難聞。屋角
隱隱約約有個人影。
LONG );
	set("exits", ([
		"east" : __DIR__"men1",
	]));
	set("objects",([
		__DIR__"npc/wulaoda" : 1,
	]));
	set("coor/x", -51050);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
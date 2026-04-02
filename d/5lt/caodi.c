// Room: /d/5lt/caodi.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
一片平緩的草地一直沿山腳延伸，偶爾有些叫不出名目的大鳥小獸
在草叢中出沒，十分自在地遊嬉。
LONG);
	set("exits", ([
		"south"      : __DIR__"qsroad",
		"northwest"  : __DIR__"fanshudi",
		"eastup"     : __DIR__"shanlu",
	]));
        set("objects", ([
	]));
	set("coor/x", -120);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
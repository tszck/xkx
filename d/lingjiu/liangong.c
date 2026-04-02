//room: liangong.c

inherit ROOM;

void create()
{
	set("short","戲鳳閣");
	set("long",@LONG
這裏是靈鷲宮弟子練功的地方。有幾個妙齡女子正在專心致致地練
武，有幾個手持竹劍,在互相拆招,身法靈動，猶如穿花蝴蝶一般，你不
禁看花了眼，別的人則坐在地上的蒲團上苦練內力。
LONG );
	set("exits",([
		"west" : __DIR__"changl4",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5
	]));
	set("coor/x", -50970);
	set("coor/y", 30140);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
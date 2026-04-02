// /kaifeng/dadao0.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "大道");
	set ("long", @LONG
在平原之上的一條大路，來往人很多，路邊相隔不遠就有個小亭子
供行人歇腳，向北去就是開封城。南面不遠是個三叉路口。
LONG);
	set("outdoors", "kaifeng");

	set("exits", ([
		"south" : __DIR__"dadao1",
		"north" : __DIR__"nanying",
	]));

	setup();
	replace_program(ROOM);
}

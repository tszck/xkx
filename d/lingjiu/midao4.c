// midao4.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
臺階終於走到了頭，眼前是一間小小的石室，周圍牆壁上插着幾盞
油燈，照得石室裏一片昏黃。北邊有一條通道。
LONG );
	set("exits", ([
		"westup" : __DIR__"midao3",
		"north": __DIR__"midao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50900);
	set("coor/y", 30170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
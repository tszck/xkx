// /kaifeng/jiedao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "野豬林");
	set ("long", @LONG
自從不久前這林子中出了野豬之後，這片松林就少人來開封境內，
談豬色邊。只有爲生活所迫的樵子還在林邊打些野柴。自認武藝高強的
圖個路近，也從此過。穿過此地便是華山。
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"northeast" : __DIR__"dadao2",
	]));
	set("objects", ([
		ANIMAL_DIR"pig" : random(2)+1,
	]));
	setup();
	replace_program(ROOM);
}

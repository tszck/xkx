//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "北樓");
	set ("long", @LONG
這是萬老爺子住的地方。擺設簡單整潔，右首一張木牀。方磚地上
有幾處凹凸，顯是主人勤於習武所致。
LONG);
	set("exits", ([
		"south" : __DIR__"dating",
		"east"  : __DIR__"shufang1",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1489);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

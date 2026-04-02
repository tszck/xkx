//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "書房");
	set ("long", @LONG
這是萬老爺子的書房。擺設簡單整潔。左首一堵白牆特別惹眼。
LONG);
	set("exits", ([
		"west" : __DIR__"beilou",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1488);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
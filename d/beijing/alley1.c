// /d/beijing/alley1.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "楊柳衚衕");
	set("long", @LONG
你走在巷道上，感到似乎有些不妙。南邊仍是空蕩蕩的小道，見不
到幾個行人。東邊是一家麪館。北邊是西長安大道。一股陰風吹來，你
禁不住打了個寒顫。 
LONG );
	set("outdoors", "beijing");

	set("exits", ([
		"east" : __DIR__"mianguan",
		"south" : __DIR__"alley2",
		"north" : __DIR__"xichang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

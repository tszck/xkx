//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "花園");
	set ("long", @LONG
這是萬家的後園，堆置了篩子、鋤頭、石臼、風扇之類雜物。在一
張小几放着一座香爐，香爐中插着三枝點燃了的線香。幾前有個人跪着
向天磕頭，不知祈着什麼願心。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west"  : __DIR__"ketang",
		"south" : __DIR__"citang",
	]));
	set("objects", ([
		__DIR__"npc/kongxincai"    : 1,
	]));
  
	set("coor/x", -1486);
	set("coor/y", 2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

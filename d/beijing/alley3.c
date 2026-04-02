// /d/beijing/alley3.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "楊柳衚衕");
	set("long", @LONG
這是一條十分僻靜的小衚衕，東南面有一家客店，隱隱約約傳來打
鬥之聲。你頗有些猶豫：要不要過去看一看呢，不會有什麼危險吧？東
北邊可以出衚衕。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"southeast" : __DIR__"kedian1",
		"northeast" : __DIR__"alley2",
	]));
	set("objects", ([
		"/d/village/npc/dipi" : 1,
		"/d/village/npc/punk" : 1,
	]));

	set("coor/x", -230);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

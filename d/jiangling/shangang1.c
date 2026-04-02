//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "山岡");
	set("long", @LONG
這是一片亂石岡子，雜草叢生，荒涼凋敝。山岡附近沒人家，離開
大路很遠，也沒人經過。山腰處有一個小小的圓土丘，上面立了一塊石
碑(bei)。
LONG );
	set("exits", ([
		"west"  : __DIR__"shandao5",
	]));
	set("item_desc", ([
		"bei" : "愛女凌霜華之墓\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1460);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
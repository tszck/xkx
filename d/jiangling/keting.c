//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "客廳");
	set ("long", @LONG
這是知府大人接待賓客的地方，擺着茶几座椅，牆上還掛了幾幅山
水條幅。茶几上新沏的一壺龍井還在冒着熱氣。
LONG);
	set("exits", ([
		"north" : __DIR__"huapu",
		"east"  : __DIR__"shanfang",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1488);
	set("coor/y", -2031);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
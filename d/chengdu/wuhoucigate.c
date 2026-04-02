// Room: wuhoucigate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "武侯祠大門");
	set("long", @LONG
這裏原來是武侯祠。大門人進人出，大多纏着武侯巾。原來武侯生前
治蜀，造福兩川，這武侯巾乃是他去世川人為其帶孝之俗。由於武侯遺愛
甚深，雖千載以下，川人頭巾仍不去首。
LONG
	);
	set("exits", ([
		"east"      : __DIR__"nanjie",
		"northwest" : __DIR__"wuhouci",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

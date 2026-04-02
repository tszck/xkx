// Room: liubeidian.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "劉備殿");
	set("long", @LONG
這裏是武侯祠的劉備殿。正中供着漢昭烈帝，高可丈許。後主卻沒得
供奉，所謂 "扶不起來" 的阿斗吧。而哭廟玉碎的北地王劉諶得能和英父
同祀，令人不勝唏噓。
    殿下左右是趙雲等的武將廊和蔣琬為首的文臣廊。
LONG );
	set("exits", ([
		"southdown" : __DIR__"wuhouci",
		"northup"   : __DIR__"zhugeliang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -3010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

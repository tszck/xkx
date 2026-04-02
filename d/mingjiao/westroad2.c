//westroad2.c

inherit ROOM;

void create()
{
	set("short", "深山");
	set("long", @TEXT
已經走了很久，山林越來越密，夜晚來臨了，夜梟呼號，令人毛骨
悚然。真是“蜀道難，難於上青天”。再向西，就要出山了。突然，你
又發現南面有零星火光。
TEXT );
	set("outdoors", "mingjiao");
	set("exits",([
		"east" : __DIR__"westroad1",
		"west" : __DIR__"gebitan1",
		"south" : __DIR__"miaorenbuluo",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
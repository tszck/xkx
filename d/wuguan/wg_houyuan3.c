// wg_houyuan3.c

inherit ROOM;

void create()
{
	set("short", "後院");
	set("long", @LONG
這裏是後院外了，四周都是菜地，往北是個小山坡，東西面都是用
籬笆圍起的菜地，種着各樣的菜，籬笆很破爛，搖搖欲墜，看來這裏沒
什麼人打理。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_caidi2",
		"south" : __DIR__"wg_caidi1",
		"west" : __DIR__"wg_houyuan2",
	]));
	set("objects", ([	    
		__DIR__"npc/wg_ryjdizi" : 1,
		__DIR__"npc/wg_baituodizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 81);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


// /guanwai/road3.c
inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
這裏是通往關外的官道，幾米寬的大道，全部由黃土鋪成，可並行
三四輛馬車而不顯擁擠。這裏是進出關口的必經之路，路上三倆成羣的
行人都是往來販運皮貨，藥材的生意人。偶爾有身着官兵騎馬飛馳而過。
LONG );
	set("exits", ([
		"north"     : __DIR__"ningyuan",
		"southwest" : __DIR__"road2",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 6020);
	set("coor/y", 5120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
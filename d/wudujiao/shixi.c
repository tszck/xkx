// Room: /d/wudujiao/shixi.c

inherit ROOM;

void create()
{
        set("short", "石隙");
        set("long", @LONG
這裏是一道岩石的縫隙，窄得要人側身擠過。你沿着曲折的巖縫
向前摸去，四周黑漆漆的，只有腳下的砂石發出輕微的聲響。
LONG
        );

	set("no_clean_up", 0);
        set("exits", ([
              "down"     : __DIR__"baidu2",
              "westdown" : __DIR__"mishi",
        ]));

	set("coor/x", -44950);
	set("coor/y", -81120);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
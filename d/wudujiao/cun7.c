// Room: /d/wudujiao/cun7.c

inherit ROOM;

void create()
{
        set("short", "小村");
        set("long", @LONG
走在小村的石板路上，兩旁都是用青石砌成的房屋。東邊有一座學堂，
裏面傳來朗朗的讀書聲。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "northwest" : __DIR__"cun5",
                "southeast" : __DIR__"cun8",
                "southwest" : __DIR__"cun6",
                "east" : __DIR__"minju7",
        ]));

	set("coor/x", -44940);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
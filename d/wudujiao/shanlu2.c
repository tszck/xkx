// Room: /d/wudujiao/shanlu2.c

inherit ROOM;

void create()
{
        set("short", "上山小路");
        set("long", @LONG
這是一條上山的小路，腳下是青石砌成的臺階，濕漉漉的長
滿了青苔，四周全是茂密的竹林。遠處傳來一陣悠揚的山歌聲。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southup"   : __DIR__"shanlu3",
                "northdown" : __DIR__"xiaolu",
        ]));

	set("coor/x", -44000);
	set("coor/y", -78110);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
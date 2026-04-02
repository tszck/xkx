// Room: /d/wudujiao/caoping.c

inherit ROOM;

void create()
{
        set("short", "臥龍崗上");
        set("long", @LONG
山頂有一大片開闊地，藍藍的天上飄着幾朵白雲，腳下是綠
油油的草地，淺淺的剛好可以蓋過腳面,散發着一種誘人的芳香
舒服的人直想躺在上面打滾。前面有幾間簡陋的竹舍。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"zhushe",
                "northdown" : __DIR__"shanlu3",
        ]));

	set("coor/x", -44000);
	set("coor/y", -78130);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
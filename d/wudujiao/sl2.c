// Room: /d/wudujiao/sl2.c

inherit ROOM;

void create()
{
        set("short", "松樹林");
        set("long", @LONG
這裏是一片濃密的松樹林，前面已經沒有了道路，你必須不時砍斷
橫在你面前的枝椏。林內光線黑暗，靜的能聽到你自己的心跳聲 ，只有
你踩在地上厚厚的松針和枯枝上發出的沙沙聲。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sl3",
                "southwest" : __DIR__"sl4",
                "west" : __DIR__"sl1",
                "southeast" : __DIR__"sl5",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81070);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
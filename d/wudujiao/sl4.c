// Room: /d/wudujiao/sl4.c

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
        set("exits", ([
                "north" : __DIR__"sl1",
                "northeast" : __DIR__"sl2",
                "south" : __DIR__"sl6",
                "southeast" : __DIR__"sl7",
        ]));
        set("objects", ([
                "/clone/medicine/nostrum/zhujingchan" : 1,
        ]));

	set("coor/x", -44940);
	set("coor/y", -81080);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
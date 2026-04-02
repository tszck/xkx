// Room: /d/wudujiao/huating1.c

inherit ROOM;

void create()
{
        set("short", "花廳");
        set("long", @LONG
這裏是一個幽雅別緻的花廳，四周掛着碧紗的幔帳，屋角香爐中飄着一
股奇異的香氣。有一個粉紅衣裙的少女正坐在窗邊發呆，聽見腳步聲不覺瞟
了你一樣，秀眉微微一顰，似乎不太高興。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"huating2",
                "north" : __DIR__"huating3",
                "west"  : __DIR__"huayuan1",
        ]));
        set("objects", ([
                CLASS_D("wudujiao")+"/hetieshou": 1,
        ]));

	set("coor/x", -44890);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
}

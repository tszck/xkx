// Room: /beijing/guancaidian.c

inherit ROOM;

void create()
{
	set("short", "棺材店");
	set("long", @LONG
這是一家棺材店，一進門，一股楠木味撲鼻而來。屋子裏很陰暗，
桌子椅子都很破舊。往東是一間內室，一個三十出頭的精壯漢子擋在門
口。
LONG );
	set("item_desc", ([
		"guancai" : "本店出售棺材，每個五十兩黃金。\n",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/gaoyanchao" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"alley2",
		"east"      : __DIR__"guancai2",
	]));
	set("coor/x", -219);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("money_paid") && dir == "up" )
	{
        if(objectp(present("gaoyanca", environment(me))))
        return notify_fail("高彥超一下擋在樓梯前，怒道：先交錢！\n");
        }
	if ( me->query_temp("money_paid") && dir == "west" )
	return notify_fail("高彥超跑到門邊攔住：客官已經付了金子，怎麼不上樓就走了呢！\n");
	return ::valid_leave(me, dir);
}

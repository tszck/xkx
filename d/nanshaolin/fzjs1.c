// Room: /d/nanshaolin/fzjs1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "茶室");
	set("long", @LONG
這裏是方丈待客的地方，靠牆左右兩側擺着一溜太師椅。北面牆上
掛了一付對聯。牆角一幾，放着幾個茶壺。有個茶壺壺身上題了“碧螺
春”三個篆字，壺嘴熱氣騰騰，似乎是剛沏的新茶。往北是方丈室。
LONG );
	set("exits", ([
		"north" : __DIR__"fzjs2",
		"down"  : __DIR__"fzjs",
	]));
	set("objects",([
		__DIR__"npc/xiao-tong" : 1,
		CLASS_D("nanshaolin")+"/fangxiang" : 1,
	]));
	set("coor/x", 1780);
	set("coor/y", -6150);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	int skill;

	skill = me->query_skill("buddhism", 1);
	if (!wizardp(me) && skill < 30)
	{
		if (dir == "north" )
		{
			return notify_fail("你資格不夠，不能進入方丈室。\n");
		}
	}
	return ::valid_leave(me, dir);
}



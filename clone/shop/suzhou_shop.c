// /clone/shop/suzhou_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "採芝齋");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/suzhou/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}

void init()
{
	if (query("shop_type") == 0)
		set("long", @LONG
採芝齋坐落於蘇州城北，是一間裝潢雅緻的店鋪。蘇州城建築別具
一格，這家店鋪也不例外。不過貨櫃上卻空無一物，看樣子已很久沒人
來打理了。
LONG);
	else
		set("long", @LONG
採芝齋坐落於蘇州城北，是一間裝潢雅緻的店鋪。蘇州城建築別具
一格，這家店鋪也不例外。此時店堂夥計正忙上忙下，招呼着客人。
LONG);
        return;
}


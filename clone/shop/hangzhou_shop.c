// /clone/shop/hangzhou_shop.c
// Last modified by winder 2003.10.20
inherit SHOP;

void create()
{
	set("short", "頤香齋");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/hangzhou/majiu",
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
頤香齋乃是由杭州城的老字號，所謂「上有天堂下有蘇杭」，杭州
城建築別具一格，這家店鋪也不例外。不過貨櫃上卻空無一物，看樣子
已很久沒人來打理了。
LONG);
	else
		set("long", @LONG
頤香齋乃是由杭州城的老字號，所謂「上有天堂下有蘇杭」，杭州
城建築別具一格，這家店鋪也不例外。店堂裝潢得典雅精緻，夥計正彬
彬有禮的招呼着客人。
LONG);
        return;
}


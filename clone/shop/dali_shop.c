// /clone/shop/dali_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "撥雲堂");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/dali/majiu",
        ]));
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("shop_type", 0);

	setup();
}

void init()
{
	if (query("shop_type") == 0)
		set("long", @LONG
這裏是大理城裏最著名的老字號，整個鋪面裝修得相當十分豔麗，
從內到外透着大西南的味兒。不過店裏的貨櫃上卻空無一物，看樣子已
經很久沒人來打理了。
LONG);
	else
		set("long", @LONG
這裏是大理城裏最著名的老字號，整個鋪面裝修得相當十分豔麗，
從內到外透着大西南的味兒。店鋪裏的夥計正招呼着客人，忙得滿頭大
汗。
LONG);
        return;
}


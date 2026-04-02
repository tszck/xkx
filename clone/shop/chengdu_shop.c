// /clone/shop/chengdu_shop.c
// Last modified by winder 2003.10.20

inherit SHOP;

void create()
{
	set("short", "清香園");
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/chengdu/majiu",
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
成都號稱天府之國，物產豐盛，富甲一時。整個店鋪裝潢雅緻，看
得出店主是費了一番心思的，不過店裏的貨櫃上卻空無一物，看樣子已
經很久沒人來打理了。
LONG);
	else
		set("long", @LONG
成都號稱天府之國，物產豐盛，富甲一時。這家殘月樓出售各式各
樣的稀有物品，都是在別地難於購買的。整個店鋪裝潢雅緻，看得出店
主是費了一番心思的。
LONG);
        return;
}


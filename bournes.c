#include "bournes.h"

void bournes_init(void) {
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOD Periph clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	/* Configure PC0 to PC7 to input pullup mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* GPIOA Periph clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/* Configure PA8 to input pullup mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

uint8_t bournes_position_get(uint8_t value) {
	switch (value) {
		case 127:
			return 0;
			break;
		case 63:
			return 1;
			break;
		case 62:
			return 2;
			break;
		case 58:
			return 3;
			break;
		case 56:
			return 4;
			break;
		case 184:
			return 5;
			break;
		case 152:
			return 6;
			break;
		case 24:
			return 7;
			break;
		case 8:
			return 8;
			break;
		case 72:
			return 9;
			break;
		case 73:
			return 10;
			break;
		case 77:
			return 11;
			break;
		case 79:
			return 12;
			break;
		case 15:
			return 13;
			break;
		case 47:
			return 14;
			break;
		case 175:
			return 15;
			break;
		case 191:
			return 16;
			break;
		case 159:
			return 17;
			break;
		case 31:
			return 18;
			break;
		case 29:
			return 19;
			break;
		case 28:
			return 20;
			break;
		case 92:
			return 21;
			break;
		case 76:
			return 22;
			break;
		case 12:
			return 23;
			break;
		case 4:
			return 24;
			break;
		case 36:
			return 25;
			break;
		case 164:
			return 26;
			break;
		case 166:
			return 27;
			break;
		case 167:
			return 28;
			break;
		case 135:
			return 29;
			break;
		case 151:
			return 30;
			break;
		case 215:
			return 31;
			break;
		case 223:
			return 32;
			break;
		case 207:
			return 33;
			break;
		case 143:
			return 34;
			break;
		case 142:
			return 35;
			break;
		case 14:
			return 36;
			break;
		case 46:
			return 37;
			break;
		case 38:
			return 38;
			break;
		case 6:
			return 39;
			break;
		case 2:
			return 40;
			break;
		case 18:
			return 41;
			break;
		case 82:
			return 42;
			break;
		case 83:
			return 43;
			break;
		case 211:
			return 44;
			break;
		case 195:
			return 45;
			break;
		case 203:
			return 46;
			break;
		case 235:
			return 47;
			break;
		case 239:
			return 48;
			break;
		case 231:
			return 49;
			break;
		case 199:
			return 50;
			break;
		case 71:
			return 51;
			break;
		case 7:
			return 52;
			break;
		case 23:
			return 53;
			break;
		case 19:
			return 54;
			break;
		case 3:
			return 55;
			break;
		case 1:
			return 56;
			break;
		case 9:
			return 57;
			break;
		case 41:
			return 58;
			break;
		case 169:
			return 59;
			break;
		case 233:
			return 60;
			break;
		case 225:
			return 61;
			break;
		case 229:
			return 62;
			break;
		case 245:
			return 63;
			break;
		case 247:
			return 64;
			break;
		case 243:
			return 65;
			break;
		case 227:
			return 66;
			break;
		case 163:
			return 67;
			break;
		case 131:
			return 68;
			break;
		case 139:
			return 69;
			break;
		case 137:
			return 70;
			break;
		case 129:
			return 71;
			break;
		case 128:
			return 72;
			break;
		case 132:
			return 73;
			break;
		case 148:
			return 74;
			break;
		case 212:
			return 75;
			break;
		case 244:
			return 76;
			break;
		case 240:
			return 77;
			break;
		case 242:
			return 78;
			break;
		case 250:
			return 79;
			break;
		case 251:
			return 80;
			break;
		case 249:
			return 81;
			break;
		case 241:
			return 82;
			break;
		case 209:
			return 83;
			break;
		case 193:
			return 84;
			break;
		case 197:
			return 85;
			break;
		case 196:
			return 86;
			break;
		case 192:
			return 87;
			break;
		case 64:
			return 88;
			break;
		case 66:
			return 89;
			break;
		case 74:
			return 90;
			break;
		case 106:
			return 91;
			break;
		case 122:
			return 92;
			break;
		case 120:
			return 93;
			break;
		case 121:
			return 94;
			break;
		case 125:
			return 95;
			break;
		case 253:
			return 96;
			break;
		case 252:
			return 97;
			break;
		case 248:
			return 98;
			break;
		case 232:
			return 99;
			break;
		case 224:
			return 100;
			break;
		case 226:
			return 101;
			break;
		case 98:
			return 102;
			break;
		case 96:
			return 103;
			break;
		case 32:
			return 104;
			break;
		case 33:
			return 105;
			break;
		case 37:
			return 106;
			break;
		case 53:
			return 107;
			break;
		case 61:
			return 108;
			break;
		case 60:
			return 109;
			break;
		case 188:
			return 110;
			break;
		case 190:
			return 111;
			break;
		case 254:
			return 112;
			break;
		case 126:
			return 113;
			break;
		case 124:
			return 114;
			break;
		case 116:
			return 115;
			break;
		case 112:
			return 116;
			break;
		case 113:
			return 117;
			break;
		case 49:
			return 118;
			break;
		case 48:
			return 119;
			break;
		case 16:
			return 120;
			break;
		case 144:
			return 121;
			break;
		case 146:
			return 122;
			break;
		case 154:
			return 123;
			break;
		case 158:
			return 124;
			break;
		case 30:
			return 125;
			break;
		case 94:
			return 126;
			break;
		case 95:
			return 127;
			break;
		default:
			return 255;
			break;
	}
}

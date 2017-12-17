/*
 * playerHandler.c
 *
 *  Created on: 03.12.2017
 *      Author: OSKI
 */


//case 'a':
//				{
//
//					PlaySong("boh.wav", &wav);
//
//					break;
//				}
//				case 'n':
//				{
//
//					PlayNextSong(&wav);
//					DisplayMenu(DEFAULT, player, wav);
//					break;
//				}
//				case 'q':
//				{
//
//					PlaySong("korn.wav", &wav);
//
//					break;
//				}
//				case 'z':
//				{
//
//					PlaySong("don44.wav", &wav);
//					break;
//				}
//				case 'x':
//				{
//
//					PlaySong("don48.wav", &wav);
//					break;
//				}
//				case 'p':
//				{
//					player.audio_pause ^= 1;
//					break;
//				}
//				case '+':
//				{
//					timer = 0;
//
//					switch (MenuState) {
//						case BASS:
//						{
//							player.lowPassVolume += 1;
//							if(player.lowPassVolume > 10) player.lowPassVolume = 10;
//							uart_putInt(player.lowPassVolume);
//							DisplayMenu(BASS, player, wav);
//							break;
//						}
//						case TREBLE:
//						{
//							player.highPassVolume += 1;
//							if(player.highPassVolume > 10) player.highPassVolume = 10;
//							DisplayMenu(TREBLE, player, wav);
//							break;
//						}
//						default:
//						{
//							player.volume += 1;
//							if(player.volume > 9)
//								player.volume = 9;
//							DisplayMenu(VOLUME, player, wav);
//							break;
//						}
//					}
//					break;
//				}
//				case '-':
//				{
//					timer = 0;
//					switch (MenuState) {
//						case BASS:
//						{
//							player.lowPassVolume -= 1;
//							if(player.lowPassVolume < -10) player.lowPassVolume = -10;
//							uart_putInt(player.lowPassVolume);
//							DisplayMenu(BASS, player, wav);
//							break;
//						}
//						case TREBLE:
//						{
//							player.highPassVolume -= 1;
//							if(player.highPassVolume < -10) player.highPassVolume = -10;
//							DisplayMenu(TREBLE, player, wav);
//							break;
//						}
//						default:
//						{
//							player.volume -= 1;
//							if(player.volume < 0)
//								player.volume = 0;
//							DisplayMenu(VOLUME, player, wav);
//							break;
//						}
//					}
//					break;
//				}
////				case 'f':
////				{
////					if(player.isPlaying)
////					{
////						player.audio_pause = 1;
////						f_lseek(&plik, f_tell(&plik) + currentSong.bitRate * 4);
////						currentSong.currentSec++;
////						if(currentSong.currentSec >= 60)
////						{
////							currentSong.currentMin++;
////							currentSong.currentSec = 0;
////						}
////						player.audio_pause = 0;
////					}
////					break;
////				}
////				case 'g':
////				{
////					if(player.isPlaying)
////					{
////						player.audio_pause = 1;
////						f_lseek(&plik, f_tell(&plik) - currentSong.bitRate * 4);
////						if(currentSong.currentSec == 0)
////						{
////							currentSong.currentMin--;
////							currentSong.currentSec = 60;
////						} else
////							currentSong.currentSec--;
////						player.audio_pause = 0;
////					}
////					break;
////				}
//				case 'm':
//				{
//					timer = -20;
//					if(MenuState == DEFAULT || MenuState == VOLUME)
//						MenuState = BASS;
//					else if(MenuState == BASS)
//						MenuState = TREBLE;
//					else if(MenuState == TREBLE)
//						MenuState = DEFAULT;
//
//					DisplayMenu(MenuState, player, wav);
//					break;
//				}
//				case 27:
//				{
//					DisplayMenu(DEFAULT, player, wav);
//					break;
//				}

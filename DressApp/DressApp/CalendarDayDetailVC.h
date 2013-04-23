//
//  CalendarDayDetailVC.h
//  DressApp
//
//  Created by Javier Sanchez Sierra on 12/9/11.
//  Copyright (c) 2011 Javier Sanchez Sierra. All rights reserved.
//
// This file is part of DressApp.

// DressApp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// DressApp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//
// Permission is hereby granted, free of charge, to any person obtaining 
// a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the 
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
// sell copies of the Software, and to permit persons to whom the Software is furnished 
// to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//https://github.com/jsanchezsierra/DressApp


#import <UIKit/UIKit.h>
#import "ConjuntoPrendaView.h"
#import "CalendarConjunto.h"
#import "CalendarHistoricoRemove.h"

@protocol CalendarDayDetailVCDelegate;

@interface CalendarDayDetailVC : UIViewController <ConjuntoPrendaViewDelegate,UIScrollViewDelegate,UITextFieldDelegate,UIActionSheetDelegate>
{
    NSString *cachesDirectory;
    NSFileManager *fileManager;
    UIAlertView *alertViewMoveToTrash;

}

@property (nonatomic, strong) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong) NSDate *dayDate;
@property (nonatomic, assign) id<CalendarDayDetailVCDelegate>delegate;
@property (nonatomic, strong) IBOutlet UIView *drawingView;
@property (nonatomic, strong) IBOutlet UIScrollView *myScrollView;   
@property (nonatomic, strong) IBOutlet UITextField *myTextField;   
@property (nonatomic, strong) IBOutlet UIImageView *myBackgroundImage;   
@property (nonatomic, strong) IBOutlet UIImageView *myFrameImage;   
@property (nonatomic, strong) IBOutlet UIImageView *myNotesImage;   


@property (nonatomic, strong) CalendarConjunto *calendarConjuntoItem;

-(void) addConjuntoViews;
-(void)textFieldUpdate:(UITextField *)textField;


@end

@protocol CalendarDayDetailVCDelegate

-(void) addNoteToCalendarDay;
-(void) didFinishEditingCalendarDay;
-(void) didMoveCalendarItemToTrash;

@end
//
//  KTPhotoScrollViewController.h
//  KTPhotoBrowser
//
//  Created by Kirby Turner on 2/4/10.
//  Copyright 2010 White Peak Software Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol KTPhotoBrowserDataSource;

@interface KTPhotoScrollViewController : UIViewController<UIScrollViewDelegate, UIActionSheetDelegate>
{
    id <KTPhotoBrowserDataSource> dataSource_;
    UIScrollView *scrollView_;
    UIToolbar *toolbar_;
    NSUInteger startWithIndex_;
    NSInteger currentIndex_;
    NSInteger photoCount_;
    
    NSMutableArray *photoViews_;
    NSArray *photos;
    
    // these values are stored off before we start rotation so we adjust our content offset appropriately during rotation
    int firstVisiblePageIndexBeforeRotation_;
    CGFloat percentScrolledIntoFirstVisiblePage_;
    
    UIStatusBarStyle statusBarStyle_;
    
    BOOL statusbarHidden_; // Determines if statusbar is hidden at initial load. In other words, statusbar remains hidden when toggling chrome.
    BOOL isChromeHidden_;
    BOOL rotationInProgress_;
    
    BOOL viewDidAppearOnce_;
    BOOL navbarWasTranslucent_;
    
    NSTimer *chromeHideTimer_;
    
    UIButton *nextButton_;
    UIBarButtonItem *previousButton_;
}

@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;
@property (nonatomic, assign, getter=isStatusbarHidden) BOOL statusbarHidden;

- (id)initWithImageArray:(NSArray *)imageArray andStartWithPhotoAtIndex:(NSUInteger)index;

- (void)toggleChromeDisplay;

@end

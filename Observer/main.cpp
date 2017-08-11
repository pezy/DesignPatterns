#include <iostream>
#include <string>
#include <vector>
#include <functional>

class JobPost {
public:
    JobPost(const std::string& title): title_(title) {}
    const std::string& GetTitle() const { return title_; }
private:
    std::string title_;
};

class IObserver {
public:
    virtual void OnJobPosted(const JobPost& job) = 0;
};

class JobSeeker : public IObserver {
public:
    JobSeeker(const std::string& name): name_(name) {}
    void OnJobPosted(const JobPost &job) override {
        std::cout << "Hi " << name_ << "! New job posted: " << job.GetTitle() << std::endl;
    }
private:
    std::string name_;
};

class IObservable {
public:
    virtual void Attach(IObserver& observer) = 0;
    virtual void AddJob(const JobPost& jobPosting) = 0;
protected:
    virtual void Notify(const JobPost& jobPosting) = 0;
};

class JobPostings : public IObservable {
public:
    void Attach(IObserver& observer) override {
        observers_.push_back(observer);
    }
    void AddJob(const JobPost &jobPosting) override {
        Notify(jobPosting);
    }
private:
    void Notify(const JobPost &jobPosting) override {
        for (IObserver& observer : observers_)
            observer.OnJobPosted(jobPosting);
    }

    std::vector<std::reference_wrapper<IObserver>> observers_;
};

int main()
{
    JobSeeker johnDoe("John Doe");
    JobSeeker janeDoe("Jane Doe");

    JobPostings jobPostings;
    jobPostings.Attach(johnDoe);
    jobPostings.Attach(janeDoe);

    jobPostings.AddJob(JobPost("Software Engineer"));
}
